/*
 * Copyright (C) 2017 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef IGNITION_RENDERING_SHADERPARAMS_HH_
#define IGNITION_RENDERING_SHADERPARAMS_HH_

#include <memory>
#include <utility>

#include <ignition/rendering/ShaderParam.hh>

namespace ignition
{
  namespace rendering
  {
    /// \brief forward declaration
    class ShaderParamsPrivate;

    /// \brief a map that holds params to be passed to a shader
    class ShaderParams
    {
      /// \brief forward declaration
      class IteratorPrivate;

      /// \brief Iterator for looping through params
      /// \remarks implements a forward-iterator
      class Iterator
      {
        /// \brief Default constructor
        public: Iterator();

        /// \brief Special constructor used by ShaderParams implementation
        public: Iterator(std::unique_ptr<IteratorPrivate> _dataPtr);

        /// \brief Copy constructor
        public: Iterator(const Iterator &_iter);

        /// \brief Copy assignment
        Iterator& operator=(const Iterator &_iter);

        /// \brief Destructor
        public: ~Iterator();

        /// \brief Equality operator
        public: bool operator==(const Iterator &_iter);

        /// \brief Inequality operator
        public: bool operator!=(const Iterator &_iter);

        /// \brief Dereference operator
        public: const std::pair<const std::string, ShaderParam> &operator*();

        /// \brief Arrow dereference operator
        public: const std::pair<const std::string, ShaderParam> *operator->();

        /// \brief prefix increment
        public: Iterator &operator++();

        /// \brief postfix increment
        public: Iterator operator++(int);

        private: std::unique_ptr<IteratorPrivate> dataPtr;
      };

      /// \brief constructor
      public: ShaderParams();

      /// \brief destructor
      public: ~ShaderParams();

      /// \brief Access a param with a given name
      /// \param[in] _name Identifier for the parameter
      /// \returns parameter reference
      public: ShaderParam &operator[](const std::string &_name);

      /// \brief Access a param with a given name
      /// \param[in] _name Identifier for the parameter
      /// \returns const parameter reference
      public: const ShaderParam &operator[](const std::string &_name) const;

      /// \brief Iterator to first parameter
      /// \remarks Necessary for range-base for loop support
      public: Iterator begin() const;

      /// \brief Iterator to one past last param
      /// \remarks Necessary for range-base for loop support
      public: Iterator end() const;

      /// \brief Have the params changed?
      /// \internal
      /// \returns true if the parameters have changed
      public: bool IsDirty() const;

      /// \brief Resets the dirty flag
      /// \internal
      public: void ClearDirty();

      /// \brief private implementation
      private: std::unique_ptr<ShaderParamsPrivate> dataPtr;
    };

    class ShaderParamsIter
    {
    };

  }
}

#endif
